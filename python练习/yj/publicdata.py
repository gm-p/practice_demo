import pymongo as pm
import numpy as np
import time
import skimage.io as io
import cv2
aws_info = {
    "credentials": {
        "aws_access_key_id": "",
        "aws_secret_access_key": "",
        "region_name": "cn-north-1"
    },
    "bucket": "",
    "prefix": ""
}
mongo_info = {
    "hostB": "",
    "portB": 27017,
    "DB":""
}
def getElevationGrid(bbox):
    client = pm.MongoClient(mongo_info['hostB'], mongo_info['portB'])
    db=client[mongo_info['DB']]
    books=db["ASTER_30M"]

    xmin=bbox['xmin']-0.02
    xmax=bbox['xmax']+0.02
    ymin=bbox['ymin']-0.02
    ymax=bbox['ymax']+0.02
    dc=[]
    dt=-0.015
    print(time.ctime(),'load from mongo elevation colection begin.')
    for i in books.find({"Location": {"$within": {"$geometry": {"type": "Polygon", "coordinates": [
        [[xmin-dt,ymin-dt], [xmax+dt, ymin-dt], [xmax+dt, ymax+dt], [xmin-dt, ymax+dt], [xmin-dt, ymin-dt]]]}}}}):

        dc.append(i)

    print(time.ctime(),'load from mongo elevation colection ok! ','total ',len(dc),'square kilometer!')
    if len(dc)==0:
        return 0;
    nx=round((xmax-xmin)/dc[0]['SpaceDelta'])
    ny=round((ymax-ymin)/dc[0]['SpaceDelta'])
    eg=np.zeros((nx,ny),dtype='int16')
    for n in dc:
        n1=round((n['Location'][0]-xmin)/n['SpaceDelta'])
        n2=round((n['Location'][1]-ymin)/n['SpaceDelta'])

        for i in range(36):
            for j in range(36):
                eg[n1+i,n2+j]=n['ElevationArray'][i*36+j]

    jq=round(0.02/dc[0]['SpaceDelta'])
    eg=eg[jq:nx-jq,jq:ny-jq]
    print(time.ctime(), 'rebuild elevation grid ok!')
    return eg

if __name__=='__main__':
    b=dict()
    b['xmin']=117.8
    b['xmax']=117.9
    b['ymin']=31.5
    b['ymax']=31.6
    eg=getElevationGrid(b)
    eg=eg.transpose()
    io.imsave('ele.tif',eg)