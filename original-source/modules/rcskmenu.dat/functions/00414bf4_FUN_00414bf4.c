/*
 * FUN_00414bf4 at 00414bf4
 * undefined __register FUN_00414bf4(int param_1, int param_2, char * param_3, char * param_4)
 * Address ranges: 00414bf4-00414c71
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414bf4(int param_1,int param_2,char *param_3,char *param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *local_10;
  undefined1 local_c;
  char *local_8;
  
  local_8 = param_3;
  if (param_2 != 0) {
    uVar1 = FUN_00407d58(param_3,param_4);
    if (((char)uVar1 == '\0') && (param_1 == *(int *)(param_2 + 4))) {
      iVar2 = FUN_00414c8c(param_1,param_4);
      if (iVar2 != 0) {
        local_10 = param_4;
        local_c = 0xb;
        uVar1 = FUN_0040ad5c((int)&DAT_0040dd54,'\x01',(undefined4 *)PTR_PTR_0047c834,0,&local_10);
        FUN_00403604(uVar1);
      }
    }
  }
  if (((*(byte *)(param_1 + 0x20) & 0x10) != 0) && (*(int *)(param_1 + 4) != 0)) {
    (**(code **)(**(int **)(param_1 + 4) + 0x20))(*(int **)(param_1 + 4),param_2,local_8,param_4);
  }
  return;
}

