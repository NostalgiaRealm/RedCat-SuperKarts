/*
 * FUN_0042f350 at 0042f350
 * undefined FUN_0042f350(void)
 * Address ranges: 0042f350-0042f469
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f350(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_58 [22];
  
  puVar1 = (undefined4 *)&stack0xffffffa4;
  local_58[0] = 0;
  local_58[1] = 3;
  local_58[2] = 8;
  local_58[3] = 9;
  local_58[4] = 10;
  local_58[5] = 0xb;
  local_58[6] = 0xc;
  local_58[7] = 0xd;
  local_58[8] = 0xe;
  local_58[9] = 0xf;
  local_58[10] = 0x10;
  local_58[0xb] = 0x11;
  local_58[0xc] = 0x12;
  local_58[0xd] = 0x13;
  local_58[0xe] = 0x14;
  local_58[0xf] = 0x15;
  local_58[0x10] = 0x16;
  local_58[0x11] = 0x17;
  local_58[0x12] = 0x18;
  local_58[0x13] = 0x19;
  local_58[0x14] = 0x1a;
  local_58[0x15] = 0x1b;
  iVar2 = 0x16;
  do {
    puVar1 = puVar1 + 1;
    FUN_0042a2f0(*puVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0048ef80();
  if (DAT_0053b9f8 == 1) {
    FUN_0042f220();
  }
  else if (DAT_0053b9f8 == 2) {
    FUN_0042f290();
  }
  puVar1 = local_58;
  iVar2 = 0x16;
  do {
    FUN_0042a420(*puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0048f520();
  return;
}

