/*
 * FUN_00477890 at 00477890
 * undefined FUN_00477890(void)
 * Address ranges: 00477890-004778aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __thiscall FUN_00477890(RECT *param_1,POINT *param_2)

{
  BOOL BVar1;
  
  BVar1 = PtInRect(param_1,*param_2);
  return BVar1 == 1;
}

