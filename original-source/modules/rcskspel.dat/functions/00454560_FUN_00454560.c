/*
 * FUN_00454560 at 00454560
 * undefined FUN_00454560(void)
 * Address ranges: 00454560-004545dd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00454560(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_18 [2];
  int local_10;
  undefined1 local_c;
  
  iVar1 = DAT_00543d44;
  local_18[0] = FUN_00454fd0(&param_1);
  if ((local_18[0] == DAT_00543d44) || (param_1 < *(int *)(local_18[0] + 0xc))) {
    local_10 = DAT_00543d44;
    piVar2 = &local_10;
  }
  else {
    piVar2 = local_18;
  }
  if (*piVar2 != iVar1) {
    local_10 = param_1;
    local_c = 0;
    piVar2 = (int *)FUN_004547f0(local_18,&local_10);
    return CONCAT31((int3)((uint)*piVar2 >> 8),*(undefined1 *)(*piVar2 + 0x10));
  }
  return (uint)piVar2 & 0xffffff00;
}

