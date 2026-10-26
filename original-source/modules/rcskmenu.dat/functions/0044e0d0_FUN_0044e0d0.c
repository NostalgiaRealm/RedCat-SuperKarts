/*
 * FUN_0044e0d0 at 0044e0d0
 * undefined __register FUN_0044e0d0(int * param_1, char param_2, undefined4 * param_3, int param_4)
 * Address ranges: 0044e0d0-0044e132
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e0d0(int *param_1,char param_2,undefined4 *param_3,int param_4)

{
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
    puStackY_24 = (undefined1 *)0x44e0e2;
    local_8 = param_3;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe0,in_stack_ffffffe4);
    param_3 = extraout_ECX;
  }
  puStackY_24 = (undefined1 *)0x44e0f1;
  local_8 = param_3;
  FUN_00403f84((int)param_3);
  puStackY_28 = &LAB_0044e133;
  uStackY_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_2c;
  puStackY_24 = &stack0xfffffffc;
  FUN_0044dbdc(param_1,'\0',extraout_ECX_00);
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_00403ba4(param_1 + 2,local_8);
  param_1[3] = param_4;
  *in_FS_OFFSET = uStackY_2c;
  puStackY_24 = &LAB_0044e13a;
  puStackY_28 = (undefined1 *)0x44e132;
  FUN_00403b50((int *)&local_8);
  return;
}

