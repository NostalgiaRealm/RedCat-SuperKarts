/*
 * FUN_004032f8 at 004032f8
 * undefined4 __register FUN_004032f8(undefined4 param_1, ULONG_PTR param_2)
 * Address ranges: 004032f8-00403314
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004032f8(undefined4 param_1,ULONG_PTR param_2)

{
  ULONG_PTR UStack_8;
  undefined4 uStack_4;
  
  uStack_4 = param_1;
  if (1 < DAT_0047b008) {
    UStack_8 = param_2;
    RaiseException(0xeedfae3,0,2,&UStack_8);
  }
  return uStack_4;
}

