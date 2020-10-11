#include "public.h"
#include "tstruct.h"
#include "seller.h"
#include "storage.h"
#include "file.h"

int appendstorage(storage *sto,good *g)
{   
    FILE *fp1=NULL,*fp2=NULL;
    good temp;

    fp1=fopen("..\\file\\warehouse\\warehouse.txt","r");
    fp2=fopen("..\\file\\storage\\storage.txt","a");
    if(fp1==NULL||fp2==NULL)
    {
        return 2;
    }
    while (!feof(fp1))
    {
        fread(&temp,sizeof(good),1,fp1);
        if(strcmp(temp.picpath,g->picpath)==0)   //用户输入的商品名在仓库中能够找到
        {
            fwrite(g,sizeof(good),1,fp2);  //写入货架文件中
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
        fread(&temp,size,1,fp);
        if(strcmp(temp.picpath,temp.picpath)!=0)
        {
            fwrite(&temp,size,1,fp2);   
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("storage.txt");
    rename("storage2.txt","storage.txt");  //对文件进行操作

    for(i=pos;i<((sto->goods_amount)-1);i++)
    {
        sto->G[i]=sto->G[i+1];   //pos后的元素全部整体前移一位
    }
    (sto->goods_amount)--;
}

int adjuststorage(storage *sto,int pos,int new_inventory,float new_price)
{
    FILE *fp=NULL;
    good temp;
    long size=sizeof(good);
    fp=fopen("..\\file\\storage\\storage.txt","r+");
    if (fp==NULL)
    {
        return 2;
    }    

    sto->G[pos].inventory=new_inventory;
    sto->G[pos].price=new_price;

    while (!feof(fp))
    {
        fread(&temp,size,1,fp);
        if(strcmp(temp.picpath,sto->G[pos].picpath)==0)
        {   
            fseek(fp,-size,SEEK_CUR);
            GoodCopy(&temp,&(sto->G[pos]));
            fwrite(&temp,size,1,fp);
            fclose(fp);
            break;
        }
    }
    
    return 1;
}