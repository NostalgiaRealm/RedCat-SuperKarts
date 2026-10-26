/*
 * FUN_0042d10c at 0042d10c
 * undefined FUN_0042d10c(void)
 * Address ranges: 0042d10c-0042d1fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042d10c(int param_1,undefined4 *param_2)

{
  int *piVar1;
  LRESULT LVar2;
  undefined4 *extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puStack_34 = &stack0xfffffffc;
  puStack_2c = (undefined4 *)0x0;
  puStack_38 = &LAB_0042d1fe;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  if ((*(char *)(param_1 + 0x217) == '\x01') && ((*(byte *)(param_1 + 0x20) & 0x10) == 0)) {
    if ((*(int *)(DAT_0047d770 + 0x38) == 0) ||
       (puStack_34 = &stack0xfffffffc, *(int *)(*(int *)(DAT_0047d770 + 0x38) + 0x23c) == 0)) {
      puStack_34 = &stack0xfffffffc;
      FUN_00405438((undefined4 *)PTR_PTR_0047c920,(int *)&puStack_2c);
      piVar1 = FUN_0040ac64((int *)&DAT_0040de0c,'\x01',puStack_2c);
      FUN_00403604(piVar1);
      param_2 = extraout_EDX;
    }
    puStack_28 = param_2 + 0x13;
    uStack_24 = *param_2;
    uStack_20 = DAT_0047d4dc;
    uStack_1c = param_2[3];
    uStack_18 = param_2[4];
    uStack_14 = param_2[5];
    uStack_10 = param_2[6];
    uStack_c = param_2[1];
    uStack_8 = param_2[8];
    LVar2 = SendMessageA(*(HWND *)(*(int *)(DAT_0047d770 + 0x38) + 0x23c),0x220,0,
                         (LPARAM)&puStack_28);
    *(LRESULT *)(param_1 + 0x14c) = LVar2;
    *(byte *)(param_1 + 0x2cc) = *(byte *)(param_1 + 0x2cc) | 0x10;
  }
  else {
    FUN_00442aac(param_1,param_2);
    *(byte *)(param_1 + 0x2cc) = *(byte *)(param_1 + 0x2cc) & 0xef;
  }
  *in_FS_OFFSET = uStack_3c;
  puStack_34 = &LAB_0042d205;
  puStack_38 = (undefined1 *)0x42d1fd;
  FUN_00403b50((int *)&puStack_2c);
  return;
}

