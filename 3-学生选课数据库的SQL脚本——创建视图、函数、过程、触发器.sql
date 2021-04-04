/********************************************************
内容：学生选课数据库的SQL脚本——创建视图、函数、过程、触发器
编写：吕顺营
时间：2013-08-13
版本：V1.0
********************************************************/
--先以xsxk身份登录PLSQL DEVELOPER
--（1）创建视图
CREATE OR REPLACE VIEW VI_STUDENT_IS 
AS
SELECT SNO 学号,SNAME 姓名,SSEX 性别,SAGE 年龄,
SDEPT 所在系 
FROM STUDENT WHERE SDEPT='IS';

CREATE VIEW VI_课程统计 AS
SELECT SDEPT 所在系,SC.CNO 课程号,CNAME 课程名,
COUNT(SC.CNO) 选课人数,
MAX(GRADE) 最高分，MIN(GRADE) 最低分，
AVG(GRADE) 平均分
FROM COURSE LEFT JOIN SC ON SC.CNO=COURSE.CNO 
JOIN STUDENT ON SC.SNO=STUDENT.SNO
GROUP BY SDEPT,SC.CNO,CNAME
ORDER BY SDEPT,SC.CNO;

--视图查询

select * from VI_STUDENT_IS;
select * from VI_课程统计;

--（2）创建序列
--用于生成ID的5位循环序列
create sequence SEQ_MAKINGID
minvalue 1
maxvalue 99999
start with 1
increment by 1
nocache
cycle;

select SEQ_MAKINGID.NEXTVAL from dual;
select SEQ_MAKINGID.Currval from dual;

--（3）创建函数
--生成ID的函数
create or replace function getID
(P_prefix in varchar2) return varchar2 is
/*
功能：用于生成需要的ID，共15位，前两位是ID类型，后8位是年月日，
然后是5位顺序号
传入参数：P_prefix—两位前缀，用于说明ID类型
返回值：15位的ID
*/
  Result varchar2(15);
begin
  Result:=P_prefix||to_char(sysdate,'yyyymmdd')
  ||lpad(SEQ_MAKINGID.nextval,5,0);  
  return(Result);
end getID;

select getID('XI') FROM DUAL;

--函数调用
select getid('XK') from dual;

--（4）创建过程
--学生选课时使用的过程——处理选课业务逻辑
create or replace procedure PR_学生选课
(P_学号 IN VARCHAR,P_所选课程号 IN VARCHAR2,P_RESULT OUT VARCHAR2)
IS
/*
功能：用于学生选课时把选课结果保存在选课表中
传入参数：P_学号——某一个学生的学号，
      P_所选课程号——若有多门课程的课程号，则用逗号分隔     
传出参数：P_RESULT——成功时：选课成功！失败时：选课失败，原因：xxx
*/
  V_所选课程号 VARCHAR2(200);
  V_一个课程号 VARCHAR2(2);
BEGIN
  --传入参数检查（如：空值时返回）
  IF P_学号 IS NULL OR P_所选课程号 IS NULL THEN
    P_RESULT:='传入参数不能空，请给出正确的参数值！';
    RETURN;
  END IF;
  
  V_所选课程号:=P_所选课程号;
  --循环取出一个选课的课程号，进行插入处理
  LOOP
    --判断是否结束循环
    EXIT WHEN V_所选课程号 IS NULL
    --取出一个课程号，并截取取出一个后剩余的课程号
    select substr(V_所选课程号,1,instr(V_所选课程号,',')-1) into V_一个课程号,
substr(V_所选课程号,instr(V_所选课程号,',')+1) into V_所选课程号 from dual;
    --检查该课程号是否已经选过（是否已经存在）
    select count(*) into v_cnt from sc where sno=P_学号 and cno=V_一个课程号;
    if v_cnt=0 then
      --插入选课记录
      insert into sc(sno,cno) values(P_学号,V_一个课程号);
    end if;
  END LOOP;
  --提交插入
  COMMIT;
  P_RESULT:='选课成功！';

  --异常处理
  EXCEPTION
    WHEN OTHERS THEN
      ROLLBACK;--撤销所做的插入操作
      P_RESULT:='选课失败，原因：'+SUBSTR(SQLERRM,1,200);
END;

/*对上述过程进行调试修改后的过程如下：
create or replace procedure PR_学生选课
(P_学号 IN VARCHAR2,P_所选课程号 IN VARCHAR2,
P_RESULT OUT VARCHAR2)
IS
/*
功能：用于学生选课时把选课结果保存在选课表中
传入参数：P_学号——某一个学生的学号，
      P_所选课程号——若有多门课程的课程号，则用逗号分隔
传出参数：P_RESULT——成功时：选课成功！失败时：选课失败，原因：xxx
*/
  V_所选课程号 VARCHAR2(200);
  V_一个课程号 VARCHAR2(2);
  V_POS        NUMBER(3); 
  v_cnt        NUMBER(3);
BEGIN
  --传入参数检查（如：空值时返回）
  IF P_学号 IS NULL OR P_所选课程号 IS NULL THEN
    P_RESULT:='传入参数不能空，请给出正确的参数值！';
    RETURN;
  END IF;

  V_所选课程号:=P_所选课程号;
  --循环取出一个选课的课程号，进行插入处理
  LOOP
    --判断是否结束循环
    EXIT WHEN V_所选课程号 IS NULL;
    --取出一个课程号，并截取取出一个后剩余的课程号
    V_POS:=instr(V_所选课程号,',');
    if v_pos>0 then
      select substr(V_所选课程号,1,V_POS-1),
          substr(V_所选课程号,V_POS+1) 
        into V_一个课程号,V_所选课程号 from dual;
    else
      V_一个课程号:=V_所选课程号;
      V_所选课程号:=null;
    end if;    
    --检查该课程号是否已经选过（是否已经存在）
    select count(*) into v_cnt from sc
    where sno=P_学号 and cno=V_一个课程号;
    if v_cnt=0 AND V_一个课程号 IS NOT NULL then
      --插入选课记录
      insert into sc(sno,cno)
      values(P_学号,V_一个课程号);
    end if;
  END LOOP;
  --提交插入
  COMMIT;
  P_RESULT:='选课成功！';

  --异常处理
  EXCEPTION
    WHEN OTHERS THEN
      ROLLBACK;--撤销所做的插入操作
      P_RESULT:='选课失败，原因：'+SUBSTR(SQLERRM,1,200);
END;
*/

--返回结果集的过程
create or replace procedure PR_获取成绩统计结果
(P_RESSET OUT SYS_REFCURSOR)is
/*
功能：用于获取各门课程的成绩统计结果
返回：各门课程的成绩统计结果的数据集
*/
begin
  OPEN P_RESSET FOR
  SELECT SDEPT 所在系,SC.CNO 课程号,CNAME 课程名,COUNT(SC.CNO) 选课人数,
MAX(GRADE) 最高分，MIN(GRADE) 最低分，AVG(GRADE) 平均分
FROM COURSE LEFT JOIN SC ON SC.CNO=COURSE.CNO 
JOIN STUDENT ON SC.SNO=STUDENT.SNO
GROUP BY SDEPT,SC.CNO,CNAME
ORDER BY SDEPT,SC.CNO;
end PR_获取成绩统计结果;
--/*
练习：
(1)假设学生毕业必须取得135个学分，
请找出所有不能毕业的学生学号、姓名、所在系、所修总学分，
用存储过程实现。
个学生的学号，统计该生已经考试过的课程的平均成绩，
请编写对应的后台程序（尽量给出多种实现方法）。
--*/

--（5）创建触发器
--适用情况1：用于对非目标表的增删改操作
/*
(2)给定某
例1、在学生选课数据库中，假设违反选课表SC中的两个外键的
动作都是NO ACTION,则在课程表COURSE上建立一个触发器
TR_COURSE_DELETE，当删除课程表（Course）的课程记录时，
把选课表（SC）中相关该课程的所有选课记录也都删除。
*/

--插入测试数据
INSERT INTO COURSE VALUES('8','MIS开发',5,3);
INSERT INTO SC VALUES('95001','8',NULL);
INSERT INTO SC VALUES('95002','8',NULL);
INSERT INTO SC VALUES('95003','8',NULL);
COMMIT;

--测试
DELETE FROM COURSE WHERE CNO='8';
COMMIT;

--建立触发器（请写出建立触发器的语句）
CREATE TRIGGER TR_DELETECOURSE
BEFORE DELETE ON COURSE 
FOR EACH ROW
BEGIN
  DELETE FROM SC WHERE CNO=:OLD.CNO;
END;

--测试
DELETE FROM COURSE WHERE CNO='8';
COMMIT;

/*
练习：
（3）在学生选课数据库中，当修改学生表（STUDENT）的学号时，
把选课表（SC）中相关该学生的所有选课记录中的学号也对应修改。
试写出完成该要求的SQL语句。
*/

--测试
UPDATE STUDENT SET SNO='95008' WHERE SNO='95003';
COMMIT;

--建立触发器（请写出建立触发器的语句）

--测试
UPDATE STUDENT SET SNO='95008' WHERE SNO='95003';
COMMIT;

--适用情况2：用于对目标表的增删改操作
--比如：完成某些列的自动计算功能，示例略

--适用情况3：用于拒绝对目标表的增删改操作

--在SC表建立触发器防止删除数据
CREATE TRIGGER TR_SCDELETE
BEFORE DELETE ON SC
BEGIN
  raise_application_error(-20102,'选课信息已被锁定，不能删除！'); 
END;












