#include "public.h"
#include "tstruct.h"
#include "seller.h"
#include "storage.h"
#include "file.h"

int appendstorage(storage *sto,good *g)
{   
    FILE *fp1=NULL,*fp2=NULL;
    good temp;
    int i=0; //循环变量,用来判断输入的商品是否重复

    fp1=fopen("..\\file\\ware\\ware.txt","r");
    fp2=fopen("..\\file\\storage\\storage.txt","a");

    if(fp2==NULL||fp1==NULL)
    {
        return 2;
    }
    
    if(sto->goods_amount==16)
    {
        return 3;
    }

    for(i=0;i<sto->goods_amount;i++)
    {
        if(strcmp(sto->G[i].picpath,g->picpath)==0)
        {
            return 4;
        }
    }
    
    while (!feof(fp1))
    {
        if(fread(&temp,sizeof(good),1,fp1)==0)
            break;
        if(strcmp(temp.picpath,g->picpath)==0&&temp.t=='\n')   //用户输入的商品名在仓库中能够找到
        {   
            strcpy(temp.inventory,g->inventory);
            strcpy(temp.price,g->price);
            fwrite(&temp,sizeof(good),1,fp2);  //写入货架文件中
             GoodCopy(&(sto->G[sto->goods_amount]),&temp);
            (sto->goods_amount)++;
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int shrinkstorage(storage *sto,int pos) 
{
    FILE *fp1=NULL,*fp2=NULL;
    good temp;
    long size=sizeof(good);
    int i=0; //循环变量

    fp1=fopen("..\\file\\storage\\storage.txt","r");
    fp2=fopen("..\\file\\storage\\storage2.txt","a");
    if(fp1==NULL||fp2==NULL)
    {
        return 2;
    }
    while(!feof(fp1))
    {
        if(fread(&temp,sizeof(good),1,fp1)==0)
            break;
        if(strcmp(temp.picpath,sto->G[pos].picpath)!=0)
        {   
            fwrite(&temp,size,1,fp2);   
        }
        else
        {
            continue;
        }
    }

    for(i=pos;i<((sto->goods_amount)-1);i++)
    {
        GoodCopy(&(sto->G[i]),&(sto->G[i+1]));   //pos后的元素全部整体前移一位
    }
    strcpy(sto->G[sto->goods_amount-1].inventory,"0");
    strcpy(sto->G[sto->goods_amount-1].price,"0");
    strcpy(sto->G[sto->goods_amount-1].picpath,"\0");

    (sto->goods_amount)--;

    fclose(fp1);
    fclose(fp2);
    remove("..\\file\\storage\\storage.txt");
    rename("..\\file\\storage\\storage2.txt","..\\file\\storage\\storage.txt");  //对文件进行操作

    return 1;
}

int adjuststorage(storage *sto,int pos,char *new_inventory,char *new_price)
{
    FILE *fp1=NULL,*fp2=NULL;
    good temp;
    
    fp1=fopen("..\\file\\storage\\storage.txt","r");
    fp2=fopen("..\\file\\storage\\storage2.txt","a");
    if(fp1==NULL||fp2==NULL)
    {
        return 2;
    }

    strcpy(sto->G[pos].inventory,new_inventory);
    strcpy(sto->G[pos].price,new_price);
    while(!feof(fp1))
    {
        if(fread(&temp,sizeof(good),1,fp1)==0)
            break;
        if(strcmp(temp.picpath,sto->G[pos].picpath)!=0)
        {
            fwrite(&temp,sizeof(good),1,fp2);
        }
        else
        {
            strcpy(temp.inventory,new_inventory);
            strcpy(temp.price,new_price);
            fwrite(&temp,sizeof(good),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("..\\file\\storage\\storage.txt");
    rename("..\\file\\storage\\storage2.txt","..\\file\\storage\\storage.txt");  //对文件进行操作
    return 1;
}