/*
 * FUN_00441790 at 00441790
 * undefined __register FUN_00441790(int * param_1, char param_2, int * param_3)
 * Address ranges: 00441790-00441881
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00441790(int *param_1,char param_2,int *param_3)

{
  undefined1 *puVar1;
  int *piVar2;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined1 extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uStackY_30;
  undefined1 *puStackY_2c;
  undefined1 *puStackY_28;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  undefined4 *local_c;
  undefined1 local_5;
  
  local_c = (undefined4 *)0x0;
  local_5 = 0;
  if (param_2 != '\0') {
    puStackY_28 = (undefined1 *)0x4417a9;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffdc,in_stack_ffffffe0);
    param_3 = extraout_ECX;
    local_5 = extraout_DL;
  }
  puStackY_2c = &LAB_00441882;
  uStackY_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStackY_30;
  puStackY_28 = &stack0xfffffffc;
  FUN_0043e850(param_1,'\0',param_3);
  puVar1 = FUN_004295d8();
  param_1[0x57] = (int)puVar1;
  piVar2 = FUN_00417cf4((int *)&PTR_FUN_00416258,'\x01',extraout_ECX_00);
  param_1[0x4c] = (int)piVar2;
  FUN_00417ea0(piVar2,param_1[0x18]);
  *(undefined1 *)(param_1 + 0x58) = 1;
  param_1[0x5c] = -1;
  *(undefined1 *)(param_1 + 0x55) = 3;
  if (*(short *)(PTR_DAT_0047c9d8 + 4) == 0x11) {
    FUN_00403b50(param_1 + 0x56);
  }
  else {
    FUN_004305c0(*(int *)PTR_DAT_0047c9bc,(int *)&local_c,extraout_ECX_01);
    FUN_00403ba4(param_1 + 0x56,local_c);
  }
  *(undefined1 *)(param_1 + 0x5f) = 0;
  *(undefined1 *)((int)param_1 + 0x122) = 0xf;
  *(undefined1 *)((int)param_1 + 0x123) = 2;
  *(undefined1 *)(param_1 + 0x49) = 1;
  param_1[0x4a] = 1;
  *in_FS_OFFSET = uStackY_30;
  puStackY_28 = &LAB_00441889;
  puStackY_2c = (undefined1 *)0x441881;
  FUN_00403b50((int *)&local_c);
  return;
}

