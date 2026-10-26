/*
 * FUN_00453e30 at 00453e30
 * undefined FUN_00453e30(void)
 * Address ranges: 00453e30-00453e8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00453e30(int *param_1)

{
  BOOL BVar1;
  RECT *lprc2;
  RECT RStack_24;
  RECT RStack_14;
  
  if (*(char *)((int)param_1 + 0x131) == '\0') {
    lprc2 = &RStack_24;
    (**(code **)(*param_1 + 0x40))(param_1,&RStack_24);
    (**(code **)(*param_1 + 0xa4))(param_1,&RStack_14);
    BVar1 = EqualRect(&RStack_14,lprc2);
    if (BVar1 != 0) {
      param_1[0x10] = param_1[0x10] | 0x40;
      goto LAB_00453e7f;
    }
  }
  param_1[0x10] = param_1[0x10] & 0xffffffbf;
LAB_00453e7f:
  FUN_0043fb04((int)param_1);
  return;
}

