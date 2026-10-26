/*
 * FUN_00483960 at 00483960
 * undefined FUN_00483960(void)
 * Address ranges: 00483960-00483b04
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00483960(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d13cb;
  local_c = ExceptionList;
  iVar1 = *(int *)(param_1 + 4);
  ExceptionList = &local_c;
  piVar2 = operator_new(iVar1 * 0x5c + 4);
  local_4 = 0;
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = piVar2 + 1;
    *piVar2 = iVar1;
    FUN_004be91c(piVar3,0x5c,iVar1,FUN_00482340,FUN_00484a60);
  }
  *(int **)(param_2 + 0x9c) = piVar3;
  *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 8);
  *(undefined1 *)(param_2 + 0x90) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)(param_2 + 0xb8) = *(undefined1 *)(param_1 + 0xd);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_2 + 200) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(param_2 + 0xcc) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_2 + 0xd0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(param_2 + 0xd8) = *(undefined4 *)(param_1 + 0xb8);
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x34);
  }
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_2 + 0x74) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(param_2 + 0x84) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_1 + 0xa4);
  *(undefined4 *)(param_2 + 0x98) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_2 + 0xe0) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(param_1 + 0x30);
  ExceptionList = local_c;
  return;
}

