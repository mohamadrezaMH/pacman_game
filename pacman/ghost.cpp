#include "ghost.h"
#include "mainwindow.h"


ghost::ghost(){

}

void ghost::move(){

}

int ghost::changeDirection(){
    int i = 0, j = 0, tempDirect;
    bool checkX = false, checkY = false;
    float blocksX[] = {10.0, 74.0, 170.0, 252.0, 334.0, 418.0, 500.0, 584.0, 678.0, 740.0}
    float blocksY[] = {8.0, 110.0, 194.0, 272.0, 342.0, 416.0, 492.0, 576.0, 660.0, 742.0}
    
    for (int k = 0; k < 10; k++){
        if (x() == blocksX[k]){
            i = k;
            checkX = true;
        }
    }

    for (int k = 0; k < 10; k++){
        if (y() == blocksY[k]){
            j = k;
            checkY = true;
        }
    }
        
    if(x() == 376.0 && y() == 272.0){
        tempDirect = random() % 2 + 2;
        return tempDirect;
    }
    if(x() == 322.0 && y() == 330.0){
        return 1;
    }
    if(x() == 322.0 && y() == 354.0){
        return 0;
    }
    if(x() == 430.0 && y() == 330.0){
        return 1;
    }
    if(x() == 430.0 && y() == 354.0){
        return 0;
    }
    if(x() == 322.0 && y() == 342.0){
        return 3;
    }
    if(x() == 430.0 && y() == 342.0){
        return 2;
    }
    if(x() == 376.0 && y() == 342.0){
        return 0;
    }
    if(checkX && checkY){
        tempDirect = random() % 4;
        if(mapDirection[i][j][tempDirect] && intersection[i][j]){
            return tempDirect;
        }
        else if(!mapDirection[i][j][tempDirect] && intersection[i][j]){
            return 4;
        }
        else{
            return direction;
        }
    }
    else{
        return direction;
    }
}

void ghost::changePics(){
    picsArg = picsArg * -1 + 1;
    if(direction < 4 )
    setPixmap(pics[direction][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::changePics2(){
    picsArg = picsArg * -1 + 1;
    setPixmap(pics[4][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::changePics3(){
    picsArg = picsArg * -1 + 1;
    setPixmap(pics[5][picsArg].scaled(50, 50, Qt::KeepAspectRatio));
}

void ghost::setDirection(int d){
    direction = d;
}

