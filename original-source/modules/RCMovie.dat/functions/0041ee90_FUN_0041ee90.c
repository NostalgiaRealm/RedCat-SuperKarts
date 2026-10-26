/*
 * FUN_0041ee90 at 0041ee90
 * undefined FUN_0041ee90(void)
 * Address ranges: 0041ee90-0041eebc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __fastcall FUN_0041ee90(int param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uStack_4;
  
  piVar2 = *(int **)(param_1 + 0xd);
  uStack_4 = 0;
  uVar1 = (**(code **)(*piVar2 + 0x18))(piVar2,&uStack_4);
  if (-1 < (int)uVar1) {
    return (uint)(piVar2 == (int *)0x1);
  }
  return uVar1 & 0xffffff00;
}

