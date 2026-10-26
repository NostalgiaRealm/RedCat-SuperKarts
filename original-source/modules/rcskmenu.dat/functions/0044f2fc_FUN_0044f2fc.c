/*
 * FUN_0044f2fc at 0044f2fc
 * bool __register FUN_0044f2fc(void)
 * Address ranges: 0044f2fc-0044f30a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_0044f2fc(void)

{
  LONG LVar1;
  
  LVar1 = ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
  return LVar1 == 0;
}

