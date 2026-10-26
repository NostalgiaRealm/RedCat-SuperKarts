/*
 * FUN_00437e30 at 00437e30
 * undefined FUN_00437e30(void)
 * Address ranges: 00437e30-00437e99
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00437e30(undefined1 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (0 < param_2) {
    *param_1 = 1;
  }
  if (param_2 < 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2;
    if (100 < param_2) {
      iVar3 = 100;
    }
  }
  uVar1 = FUN_0049e2f0(s_MOTOR_004ec164);
  uVar2 = FUN_0049e2f0(s_MUSIC_004ec15c);
  FUN_0049e970(~(uVar1 | uVar2),iVar3);
  if (param_2 == 0) {
    FUN_00437be0();
    *param_1 = 0;
  }
  return;
}

