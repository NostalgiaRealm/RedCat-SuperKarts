/*
 * FUN_00454c18 at 00454c18
 * undefined __register FUN_00454c18(int * param_1, char param_2, undefined4 param_3, undefined4 * param_4)
 * Address ranges: 00454c18-00454c73
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454c18(int *param_1,char param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_2c;
  undefined1 *puStackY_28;
  undefined1 *puStackY_24;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  if (param_2 != '\0') {
    puStackY_24 = (undefined1 *)0x454c2a;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
  }
  puStackY_24 = (undefined1 *)0x454c39;
  FUN_00403f84((int)param_4);
  puStackY_28 = &LAB_00454c74;
  uStackY_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_2c;
  puStackY_24 = &stack0xfffffffc;
  FUN_0044dbdc(param_1,'\0',extraout_ECX_00);
  *(char *)(param_1 + 1) = (char)param_3;
  FUN_00403ba4(param_1 + 2,param_4);
  *in_FS_OFFSET = uStackY_2c;
  puStackY_24 = &LAB_00454c7b;
  puStackY_28 = (undefined1 *)0x454c73;
  FUN_00403b50((int *)&param_4);
  return;
}

