/*
 * FUN_0046c324 at 0046c324
 * undefined FUN_0046c324(void)
 * Address ranges: 0046c324-0046c409
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0046c324(int *param_1,char param_2,int *param_3)

{
  byte bVar1;
  int *extraout_ECX;
  char extraout_DL;
  char cVar2;
  uint uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar2 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar2 = extraout_DL;
  }
  FUN_00447088(param_1,'\0',param_3);
  param_1[0x10] = param_1[0x10] | 0x40;
  FUN_0046c488((int)param_1);
  *(undefined2 *)(param_1 + 0xa2) = 0x1ff;
  *(undefined2 *)((int)param_1 + 0x28a) = 0x1ff;
  *(undefined2 *)(param_1 + 0xa3) = 0x1ff;
  bVar1 = 0;
  do {
    uVar3 = (uint)bVar1;
    *(undefined1 *)(param_1 + uVar3 * 4 + 0x7e) = 1;
    *(undefined1 *)((int)param_1 + uVar3 * 0x10 + 0x1f9) = 1;
    *(undefined1 *)((int)param_1 + uVar3 * 0x10 + 0x1fa) = 1;
    *(undefined1 *)((int)param_1 + uVar3 * 0x10 + 0x1fb) = 0;
    bVar1 = bVar1 + 1;
  } while (bVar1 != 9);
  FUN_0043eeb0(param_1,0xf0);
  FUN_0043eed0(param_1,0x1e);
  *(undefined1 *)(param_1 + 0xb2) = 0;
  *(undefined1 *)(param_1 + 0xc1) = 1;
  *(undefined1 *)((int)param_1 + 0x305) = 0;
  *(undefined1 *)((int)param_1 + 0x306) = 1;
  *(undefined1 *)(param_1 + 0xb7) = 0;
  FUN_00445950((int)param_1,'\x01');
  if (cVar2 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

