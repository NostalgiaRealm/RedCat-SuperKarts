/*
 * FUN_00462770 at 00462770
 * undefined FUN_00462770(void)
 * Address ranges: 00462770-00462801
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00462770(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  float10 fVar5;
  float local_4c;
  float local_48;
  float local_44;
  undefined1 local_40 [64];
  
  puVar1 = (undefined4 *)FUN_004a1a40(local_40,DAT_004f3910,DAT_004f3914,DAT_00544ad0);
  puVar3 = (undefined4 *)(param_1 + 0x48);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  fVar4 = (float10)fptan((float10)DAT_00544ad0 * (float10)0.5);
  fVar5 = ((float10)2.0 / (float10)_DAT_004f391c) *
          ((float10)_DAT_004f391c / (float10)_DAT_004f3918) * fVar4 * (float10)DAT_004f3910;
  local_4c = (float)(((float10)2.0 / (float10)_DAT_004f3918) * fVar4 * (float10)DAT_004f3910);
  local_48 = (float)fVar5;
  local_44 = (float)fVar5;
  FUN_00459ce0(&local_4c);
  return;
}

