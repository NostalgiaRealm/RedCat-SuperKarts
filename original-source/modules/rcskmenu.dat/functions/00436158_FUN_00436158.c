/*
 * FUN_00436158 at 00436158
 * int * __register FUN_00436158(int * param_1, char param_2, int * param_3)
 * Address ranges: 00436158-004361d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_00436158(int *param_1,char param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar3 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar3 = extraout_DL;
  }
  FUN_00414778(param_1,'\0',param_3);
  *(undefined1 *)((int)param_1 + 0x32) = 1;
  *(undefined1 *)((int)param_1 + 0x2d) = 1;
  *(undefined1 *)((int)param_1 + 0x2f) = 2;
  *(undefined1 *)(param_1 + 0xc) = 2;
  uVar1 = FUN_00435cd0();
  *(short *)(param_1 + 0x11) = (short)uVar1;
  param_1[0xd] = -1;
  iVar2 = FUN_00402e7c((int *)&DAT_004335c4,'\x01',extraout_ECX_00);
  param_1[0x1b] = iVar2;
  *(int **)(iVar2 + 0xc) = param_1;
  *(undefined1 **)(iVar2 + 8) = &LAB_00438944;
  if (cVar3 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe0;
  }
  return param_1;
}

