/*
 * FUN_00454c9c at 00454c9c
 * undefined __register FUN_00454c9c(int param_1, char param_2, undefined4 * param_3)
 * Address ranges: 00454c9c-00454cfa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454c9c(int param_1,char param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_2c;
  undefined1 *puStackY_28;
  undefined1 *puStackY_24;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  undefined4 *local_8;
  
  if (param_2 != '\0') {
    puStackY_24 = (undefined1 *)0x454cae;
    local_8 = param_3;
    param_1 = FUN_004031ac(param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
  }
  puStackY_24 = (undefined1 *)0x454cbd;
  local_8 = param_3;
  FUN_00403f84((int)param_3);
  puStackY_28 = &LAB_00454cfb;
  uStackY_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_2c;
  puStackY_24 = &stack0xfffffffc;
  FUN_00403ba4((int *)(param_1 + 4),local_8);
  uVar1 = FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',extraout_ECX_00);
  *(undefined4 *)(param_1 + 8) = uVar1;
  *in_FS_OFFSET = uStackY_2c;
  puStackY_24 = &LAB_00454d02;
  puStackY_28 = (undefined1 *)0x454cfa;
  FUN_00403b50((int *)&local_8);
  return;
}

