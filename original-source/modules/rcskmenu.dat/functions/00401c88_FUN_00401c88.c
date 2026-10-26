/*
 * FUN_00401c88 at 00401c88
 * undefined4 * __register FUN_00401c88(uint param_1)
 * Address ranges: 00401c88-00401cb6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00401c88(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0047d494;
  while( true ) {
    if ((undefined4 **)puVar1 == &DAT_0047d494) {
      DAT_0047d434 = 3;
      return (undefined4 *)0x0;
    }
    if (((uint)puVar1[2] <= param_1) && (param_1 < (uint)(puVar1[2] + puVar1[3]))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

