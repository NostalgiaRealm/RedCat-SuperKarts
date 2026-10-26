/*
 * FUN_00434ea0 at 00434ea0
 * undefined FUN_00434ea0(void)
 * Address ranges: 00434ea0-00434f11
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434ea0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *local_18 [4];
  char *local_8;
  char *local_4;
  
  local_18[0] = s_SOFT_CAR_HIT1_004ebc20;
  local_18[1] = s_SOFT_CAR_HIT2_004ebc30;
  local_18[2] = s_MID_CAR_HIT1_004ebc40;
  local_18[3] = s_MID_CAR_HIT2_004ebc50;
  local_8 = s_HARD_CAR_HIT1_004ebc60;
  local_4 = s_HARD_CAR_HIT2_004ebc70;
  DAT_0053bad8 = FUN_0043b5b0(s_SCHUUR_004ebc80);
  iVar2 = 0;
  do {
    iVar3 = 2;
    do {
      uVar1 = FUN_0043b5b0(*(undefined4 *)((int)local_18 + iVar2));
      *(undefined4 *)((int)&DAT_0053bac0 + iVar2) = uVar1;
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  } while (iVar2 < 0x18);
  return;
}

