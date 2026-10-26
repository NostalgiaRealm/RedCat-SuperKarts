/*
 * FUN_00404ef0 at 00404ef0
 * int __register FUN_00404ef0(int param_1)
 * Address ranges: 00404ef0-00404f13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00404ef0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0047b01c;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return param_1;
    }
    if (((param_1 == puVar1[1]) || (param_1 == puVar1[2])) || (param_1 == puVar1[3])) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[4];
}

