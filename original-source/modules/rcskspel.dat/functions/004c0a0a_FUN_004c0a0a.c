/*
 * FUN_004c0a0a at 004c0a0a
 * undefined FUN_004c0a0a(void)
 * Address ranges: 004c0a0a-004c0a5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c0a0a(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  FUN_004c1305(param_1);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffcf;
  if (uVar1 == 0xffffffff) {
    puVar2 = &DAT_005034d0;
  }
  else {
    puVar2 = (undefined *)((&DAT_006b6a60)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 8);
  }
  puVar2[4] = puVar2[4] & 0xfd;
  if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffffc;
  }
  FUN_004c736a(uVar1,0,0);
  return;
}

