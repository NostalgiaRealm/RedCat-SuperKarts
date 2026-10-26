/*
 * FUN_00423280 at 00423280
 * undefined FUN_00423280(void)
 * Address ranges: 00423280-004233bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423280(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  int local_4;
  
  puVar3 = &DAT_005091b0;
  do {
    local_4 = 0x11;
    puVar4 = puVar3;
    do {
      iVar1 = __ftol();
      uVar2 = 0x100 - iVar1;
      if ((int)uVar2 < 0x80) {
        uVar2 = 0x80;
      }
      else if (0xff < (int)uVar2) {
        uVar2 = 0xff;
      }
      puVar4[-2] = (uint)(float)(extraout_ST0 + (float10)100.0);
      *puVar4 = ((uVar2 | 0x6400) << 8 | uVar2) << 8 | uVar2;
      iVar1 = __ftol();
      uVar2 = 0x100 - iVar1;
      if ((int)uVar2 < 0x80) {
        uVar2 = 0x80;
      }
      else if (0xff < (int)uVar2) {
        uVar2 = 0xff;
      }
      puVar4[6] = (uint)(float)(extraout_ST0_00 + (float10)100.0);
      puVar3 = puVar4 + 0x10;
      local_4 = local_4 + -1;
      puVar4[8] = ((uVar2 | 0x6400) << 8 | uVar2) << 8 | uVar2;
      puVar4 = puVar3;
    } while (local_4 != 0);
  } while ((int)puVar3 < 0x50bc30);
  return;
}

