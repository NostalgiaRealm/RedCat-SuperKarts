/*
 * FUN_00414230 at 00414230
 * undefined __register FUN_00414230(int param_1, undefined4 param_2, uint param_3)
 * Address ranges: 00414230-00414266;004142bc-0041438c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414230(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  int local_c;
  int local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_c = 0;
  puStack_14 = &LAB_0041438d;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  local_8 = param_1;
  uVar1 = FUN_004140d0(param_1,0,param_3);
  uVar1 = uVar1 & 0x7f;
  switch(uVar1) {
  case 1:
    FUN_0041412c(uVar1,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 2:
    FUN_00414154(1,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 3:
    FUN_00414154(2,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 4:
    FUN_00414154(4,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 5:
    FUN_00414154(10,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 6:
  case 7:
    FUN_00413fec(local_8,&local_c,extraout_ECX);
    break;
  case 10:
    FUN_004141a8(uVar1,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0xb:
    FUN_004140e4(local_8,extraout_EDX,extraout_ECX);
    break;
  case 0xc:
    FUN_004141a8(uVar1,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0xe:
    FUN_004141d0(uVar1,extraout_EDX,extraout_ECX,(uint)&stack0xfffffffc);
    break;
  case 0xf:
    FUN_00414154(4,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0x10:
    FUN_00414154(8,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0x11:
    FUN_00414154(8,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0x12:
    FUN_004141a8(uVar1,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
    break;
  case 0x13:
    FUN_00414154(8,extraout_EDX,extraout_ECX,(int)&stack0xfffffffc);
  }
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_00414394;
  puStack_14 = (undefined1 *)0x41438c;
  FUN_00403b50(&local_c);
  return;
}

