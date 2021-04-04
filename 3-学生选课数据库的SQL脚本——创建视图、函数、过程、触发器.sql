/********************************************************
���ݣ�ѧ��ѡ�����ݿ��SQL�ű�����������ͼ�����������̡�������
��д����˳Ӫ
ʱ�䣺2013-08-13
�汾��V1.0
********************************************************/
--����xsxk��ݵ�¼PLSQL DEVELOPER
--��1��������ͼ
CREATE OR REPLACE VIEW VI_STUDENT_IS 
AS
SELECT SNO ѧ��,SNAME ����,SSEX �Ա�,SAGE ����,
SDEPT ����ϵ 
FROM STUDENT WHERE SDEPT='IS';

CREATE VIEW VI_�γ�ͳ�� AS
SELECT SDEPT ����ϵ,SC.CNO �γ̺�,CNAME �γ���,
COUNT(SC.CNO) ѡ������,
MAX(GRADE) ��߷֣�MIN(GRADE) ��ͷ֣�
AVG(GRADE) ƽ����
FROM COURSE LEFT JOIN SC ON SC.CNO=COURSE.CNO 
JOIN STUDENT ON SC.SNO=STUDENT.SNO
GROUP BY SDEPT,SC.CNO,CNAME
ORDER BY SDEPT,SC.CNO;

--��ͼ��ѯ

select * from VI_STUDENT_IS;
select * from VI_�γ�ͳ��;

--��2����������
--��������ID��5λѭ������
create sequence SEQ_MAKINGID
minvalue 1
maxvalue 99999
start with 1
increment by 1
nocache
cycle;

select SEQ_MAKINGID.NEXTVAL from dual;
select SEQ_MAKINGID.Currval from dual;

--��3����������
--����ID�ĺ���
create or replace function getID
(P_prefix in varchar2) return varchar2 is
/*
���ܣ�����������Ҫ��ID����15λ��ǰ��λ��ID���ͣ���8λ�������գ�
Ȼ����5λ˳���
���������P_prefix����λǰ׺������˵��ID����
����ֵ��15λ��ID
*/
  Result varchar2(15);
begin
  Result:=P_prefix||to_char(sysdate,'yyyymmdd')
  ||lpad(SEQ_MAKINGID.nextval,5,0);  
  return(Result);
end getID;

select getID('XI') FROM DUAL;

--��������
select getid('XK') from dual;

--��4����������
--ѧ��ѡ��ʱʹ�õĹ��̡�������ѡ��ҵ���߼�
create or replace procedure PR_ѧ��ѡ��
(P_ѧ�� IN VARCHAR,P_��ѡ�γ̺� IN VARCHAR2,P_RESULT OUT VARCHAR2)
IS
/*
���ܣ�����ѧ��ѡ��ʱ��ѡ�ν��������ѡ�α���
���������P_ѧ�š���ĳһ��ѧ����ѧ�ţ�
      P_��ѡ�γ̺š������ж��ſγ̵Ŀγ̺ţ����ö��ŷָ�     
����������P_RESULT�����ɹ�ʱ��ѡ�γɹ���ʧ��ʱ��ѡ��ʧ�ܣ�ԭ��xxx
*/
  V_��ѡ�γ̺� VARCHAR2(200);
  V_һ���γ̺� VARCHAR2(2);
BEGIN
  --���������飨�磺��ֵʱ���أ�
  IF P_ѧ�� IS NULL OR P_��ѡ�γ̺� IS NULL THEN
    P_RESULT:='����������ܿգ��������ȷ�Ĳ���ֵ��';
    RETURN;
  END IF;
  
  V_��ѡ�γ̺�:=P_��ѡ�γ̺�;
  --ѭ��ȡ��һ��ѡ�εĿγ̺ţ����в��봦��
  LOOP
    --�ж��Ƿ����ѭ��
    EXIT WHEN V_��ѡ�γ̺� IS NULL
    --ȡ��һ���γ̺ţ�����ȡȡ��һ����ʣ��Ŀγ̺�
    select substr(V_��ѡ�γ̺�,1,instr(V_��ѡ�γ̺�,',')-1) into V_һ���γ̺�,
substr(V_��ѡ�γ̺�,instr(V_��ѡ�γ̺�,',')+1) into V_��ѡ�γ̺� from dual;
    --���ÿγ̺��Ƿ��Ѿ�ѡ�����Ƿ��Ѿ����ڣ�
    select count(*) into v_cnt from sc where sno=P_ѧ�� and cno=V_һ���γ̺�;
    if v_cnt=0 then
      --����ѡ�μ�¼
      insert into sc(sno,cno) values(P_ѧ��,V_һ���γ̺�);
    end if;
  END LOOP;
  --�ύ����
  COMMIT;
  P_RESULT:='ѡ�γɹ���';

  --�쳣����
  EXCEPTION
    WHEN OTHERS THEN
      ROLLBACK;--���������Ĳ������
      P_RESULT:='ѡ��ʧ�ܣ�ԭ��'+SUBSTR(SQLERRM,1,200);
END;

/*���������̽��е����޸ĺ�Ĺ������£�
create or replace procedure PR_ѧ��ѡ��
(P_ѧ�� IN VARCHAR2,P_��ѡ�γ̺� IN VARCHAR2,
P_RESULT OUT VARCHAR2)
IS
/*
���ܣ�����ѧ��ѡ��ʱ��ѡ�ν��������ѡ�α���
���������P_ѧ�š���ĳһ��ѧ����ѧ�ţ�
      P_��ѡ�γ̺š������ж��ſγ̵Ŀγ̺ţ����ö��ŷָ�
����������P_RESULT�����ɹ�ʱ��ѡ�γɹ���ʧ��ʱ��ѡ��ʧ�ܣ�ԭ��xxx
*/
  V_��ѡ�γ̺� VARCHAR2(200);
  V_һ���γ̺� VARCHAR2(2);
  V_POS        NUMBER(3); 
  v_cnt        NUMBER(3);
BEGIN
  --���������飨�磺��ֵʱ���أ�
  IF P_ѧ�� IS NULL OR P_��ѡ�γ̺� IS NULL THEN
    P_RESULT:='����������ܿգ��������ȷ�Ĳ���ֵ��';
    RETURN;
  END IF;

  V_��ѡ�γ̺�:=P_��ѡ�γ̺�;
  --ѭ��ȡ��һ��ѡ�εĿγ̺ţ����в��봦��
  LOOP
    --�ж��Ƿ����ѭ��
    EXIT WHEN V_��ѡ�γ̺� IS NULL;
    --ȡ��һ���γ̺ţ�����ȡȡ��һ����ʣ��Ŀγ̺�
    V_POS:=instr(V_��ѡ�γ̺�,',');
    if v_pos>0 then
      select substr(V_��ѡ�γ̺�,1,V_POS-1),
          substr(V_��ѡ�γ̺�,V_POS+1) 
        into V_һ���γ̺�,V_��ѡ�γ̺� from dual;
    else
      V_һ���γ̺�:=V_��ѡ�γ̺�;
      V_��ѡ�γ̺�:=null;
    end if;    
    --���ÿγ̺��Ƿ��Ѿ�ѡ�����Ƿ��Ѿ����ڣ�
    select count(*) into v_cnt from sc
    where sno=P_ѧ�� and cno=V_һ���γ̺�;
    if v_cnt=0 AND V_һ���γ̺� IS NOT NULL then
      --����ѡ�μ�¼
      insert into sc(sno,cno)
      values(P_ѧ��,V_һ���γ̺�);
    end if;
  END LOOP;
  --�ύ����
  COMMIT;
  P_RESULT:='ѡ�γɹ���';

  --�쳣����
  EXCEPTION
    WHEN OTHERS THEN
      ROLLBACK;--���������Ĳ������
      P_RESULT:='ѡ��ʧ�ܣ�ԭ��'+SUBSTR(SQLERRM,1,200);
END;
*/

--���ؽ�����Ĺ���
create or replace procedure PR_��ȡ�ɼ�ͳ�ƽ��
(P_RESSET OUT SYS_REFCURSOR)is
/*
���ܣ����ڻ�ȡ���ſγ̵ĳɼ�ͳ�ƽ��
���أ����ſγ̵ĳɼ�ͳ�ƽ�������ݼ�
*/
begin
  OPEN P_RESSET FOR
  SELECT SDEPT ����ϵ,SC.CNO �γ̺�,CNAME �γ���,COUNT(SC.CNO) ѡ������,
MAX(GRADE) ��߷֣�MIN(GRADE) ��ͷ֣�AVG(GRADE) ƽ����
FROM COURSE LEFT JOIN SC ON SC.CNO=COURSE.CNO 
JOIN STUDENT ON SC.SNO=STUDENT.SNO
GROUP BY SDEPT,SC.CNO,CNAME
ORDER BY SDEPT,SC.CNO;
end PR_��ȡ�ɼ�ͳ�ƽ��;
--/*
��ϰ��
(1)����ѧ����ҵ����ȡ��135��ѧ�֣�
���ҳ����в��ܱ�ҵ��ѧ��ѧ�š�����������ϵ��������ѧ�֣�
�ô洢����ʵ�֡�
��ѧ����ѧ�ţ�ͳ�Ƹ����Ѿ����Թ��Ŀγ̵�ƽ���ɼ���
���д��Ӧ�ĺ�̨���򣨾�����������ʵ�ַ�������
--*/

--��5������������
--�������1�����ڶԷ�Ŀ������ɾ�Ĳ���
/*
(2)����ĳ
��1����ѧ��ѡ�����ݿ��У�����Υ��ѡ�α�SC�е����������
��������NO ACTION,���ڿγ̱�COURSE�Ͻ���һ��������
TR_COURSE_DELETE����ɾ���γ̱�Course���Ŀγ̼�¼ʱ��
��ѡ�α�SC������ظÿγ̵�����ѡ�μ�¼Ҳ��ɾ����
*/

--�����������
INSERT INTO COURSE VALUES('8','MIS����',5,3);
INSERT INTO SC VALUES('95001','8',NULL);
INSERT INTO SC VALUES('95002','8',NULL);
INSERT INTO SC VALUES('95003','8',NULL);
COMMIT;

--����
DELETE FROM COURSE WHERE CNO='8';
COMMIT;

--��������������д����������������䣩
CREATE TRIGGER TR_DELETECOURSE
BEFORE DELETE ON COURSE 
FOR EACH ROW
BEGIN
  DELETE FROM SC WHERE CNO=:OLD.CNO;
END;

--����
DELETE FROM COURSE WHERE CNO='8';
COMMIT;

/*
��ϰ��
��3����ѧ��ѡ�����ݿ��У����޸�ѧ����STUDENT����ѧ��ʱ��
��ѡ�α�SC������ظ�ѧ��������ѡ�μ�¼�е�ѧ��Ҳ��Ӧ�޸ġ�
��д����ɸ�Ҫ���SQL��䡣
*/

--����
UPDATE STUDENT SET SNO='95008' WHERE SNO='95003';
COMMIT;

--��������������д����������������䣩

--����
UPDATE STUDENT SET SNO='95008' WHERE SNO='95003';
COMMIT;

--�������2�����ڶ�Ŀ������ɾ�Ĳ���
--���磺���ĳЩ�е��Զ����㹦�ܣ�ʾ����

--�������3�����ھܾ���Ŀ������ɾ�Ĳ���

--��SC������������ֹɾ������
CREATE TRIGGER TR_SCDELETE
BEFORE DELETE ON SC
BEGIN
  raise_application_error(-20102,'ѡ����Ϣ�ѱ�����������ɾ����'); 
END;












