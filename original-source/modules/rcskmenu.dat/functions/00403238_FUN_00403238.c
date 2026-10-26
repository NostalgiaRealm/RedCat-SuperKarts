/*
 * FUN_00403238 at 00403238
 * undefined4 __register FUN_00403238(undefined4 param_1, ULONG_PTR param_2)
 * Address ranges: 00403238-00403257
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00403238(undefined4 param_1,ULONG_PTR param_2)

{
  ULONG_PTR UStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (DAT_0047b008 != '\0') {
    UStack_c = param_2;
    uStack_8 = param_1;
    uStack_4 = param_1;
    RaiseException(0xeedfae4,0,2,&UStack_c);
    param_1 = uStack_4;
  }
  return param_1;
}

