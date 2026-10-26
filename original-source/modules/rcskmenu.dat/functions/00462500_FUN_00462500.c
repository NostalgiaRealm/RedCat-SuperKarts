/*
 * FUN_00462500 at 00462500
 * undefined __register FUN_00462500(int * param_1, char param_2, int param_3)
 * Address ranges: 00462500-004625c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00462500(int *param_1,char param_2,int param_3)

{
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_130;
  undefined1 *puStackY_12c;
  undefined1 *puStackY_128;
  undefined4 in_stack_fffffedc;
  undefined4 in_stack_fffffee0;
  byte local_108 [256];
  int local_8;
  
  local_8 = 0;
  if (param_2 != '\0') {
    puStackY_128 = (undefined1 *)0x46251d;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_fffffedc,in_stack_fffffee0);
    param_3 = extraout_ECX;
  }
  puStackY_12c = &LAB_004625c2;
  uStackY_130 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_130;
  iVar1 = param_3;
  puStackY_128 = &stack0xfffffffc;
  if (param_3 == 0) {
    puStackY_128 = &stack0xfffffffc;
    FUN_00402df8(*param_1,local_108);
    FUN_00403d74(&local_8,local_108);
    FUN_00403dd8(&local_8,(undefined4 *)".Create: aControl must be assigned");
    FUN_00403b34(local_8);
    iVar1 = extraout_ECX_00;
  }
  FUN_00402e7c(param_1,'\0',iVar1);
  param_1[1] = param_3;
  param_1[2] = -0x7ffffff1;
  param_1[3] = -0x7ffffff0;
  param_1[4] = -0x7fffffec;
  param_1[5] = -0x7fffffea;
  param_1[6] = -0x7fffffeb;
  param_1[7] = -0x7fffffea;
  param_1[8] = -0x7ffffff0;
  *in_FS_OFFSET = uStackY_130;
  puStackY_128 = &LAB_004625c9;
  puStackY_12c = (undefined1 *)0x4625c1;
  FUN_00403b50(&local_8);
  return;
}

