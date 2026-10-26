/*
 * FUN_0042afb4 at 0042afb4
 * int * __register FUN_0042afb4(int * param_1, char param_2, int * param_3)
 * Address ranges: 0042afb4-0042b10b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0042afb4(int *param_1,char param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  char extraout_DL;
  char cVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar5;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  cVar4 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
    cVar4 = extraout_DL;
  }
  FUN_0042a4e8(param_1,'\0',param_3);
  param_1[0x10] = 0xab;
  FUN_0043ee6c(param_1,0);
  FUN_0043ee8c(param_1,0);
  FUN_0043eeb0(param_1,0x140);
  FUN_0043eed0(param_1,0xf0);
  FUN_0042bbb8(param_1,0,extraout_ECX_00);
  FUN_0043f7fc((int)param_1,'\0');
  FUN_0043f770((int)param_1,'\0');
  FUN_00445864((int)param_1,'\x01');
  *(undefined1 *)(param_1 + 0x84) = 7;
  *(undefined1 *)((int)param_1 + 0x211) = 2;
  *(undefined1 *)((int)param_1 + 0x213) = 0;
  *(undefined1 *)((int)param_1 + 0x219) = 3;
  piVar1 = FUN_0041e048((int *)&PTR_FUN_004169a0,'\x01',extraout_ECX_01);
  param_1[0x8a] = (int)piVar1;
  uVar5 = 0x31;
  uVar2 = (**(code **)PTR_DAT_0047c734)();
  (**(code **)(*piVar1 + 0x40))(piVar1,uVar2,*piVar1,uVar5);
  uVar2 = (**(code **)PTR_DAT_0047c734)();
  (**(code **)(*(int *)param_1[0x8a] + 0x34))((int *)param_1[0x8a],uVar2);
  iVar3 = param_1[0x8a];
  *(int **)(iVar3 + 0xc) = param_1;
  *(code **)(iVar3 + 8) = FUN_0042b854;
  *(undefined1 *)(param_1 + 0x8b) = 0;
  piVar1 = FUN_00417ff0((int *)&PTR_FUN_0043aeac,'\x01',extraout_ECX_02);
  param_1[0x88] = (int)piVar1;
  FUN_0043e3e0(piVar1,(int)param_1);
  param_1[0x91] = *(int *)(DAT_0047d774 + 0x34);
  *(undefined1 *)((int)param_1 + 0x21d) = 1;
  iVar3 = FUN_00402df4(param_1);
  param_1[0x29] = iVar3;
  FUN_00430248(DAT_0047d774,param_1);
  if (cVar4 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = 0x32;
  }
  return param_1;
}

