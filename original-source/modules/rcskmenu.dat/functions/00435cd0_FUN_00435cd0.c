/*
 * FUN_00435cd0 at 00435cd0
 * uint __register FUN_00435cd0(void)
 * Address ranges: 00435cd0-00435cef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00435cd0(void)

{
  uint uVar1;
  
  uVar1 = FUN_0040fc04(DAT_0047d7a4);
  FUN_0040fbd8(DAT_0047d7a4,uVar1 & 0xffff,'\x01');
  return uVar1;
}

