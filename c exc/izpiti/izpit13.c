#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char title[51];
    char singer[41];
    int song;
}Album;

int main(){
    FILE*bin=fopen("music.bin","rb");
    if(bin==NULL) return 1;
    fseek(bin,0,SEEK_END);
    int fsize = ftell(bin);rewind(bin);
    int size=1;
    Album*list=(Album*)malloc(size*sizeof(Album));
    if(list==NULL){
        fclose(bin);
        return 1;
    }
    while(ftell(bin)<=fsize){
        Album ent;
        int sizet;
        fread(&sizet, sizeof(int),1,bin);
        fread(ent.title,sizet,1,bin);
        fread(ent.singer,40, 1, bin);
        fread(&ent.song, sizeof(int), 1,bin);
        Album*temp=(Album*)realloc(list, (++size)*sizeof(Album));
        if(temp==NULL){
            free(list);
            fclose(bin);
            return 1;
        }
        list = temp;
        list[size-1]=ent;
    }
    free(list);
    fclose(bin);
    return 0;
}