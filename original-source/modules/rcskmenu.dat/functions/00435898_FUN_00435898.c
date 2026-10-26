/*
 * FUN_00435898 at 00435898
 * HANDLE __register FUN_00435898(POINT * param_1)
 * Address ranges: 00435898-004358c6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

HANDLE FUN_00435898(POINT *param_1)

{
  HANDLE pvVar1;
  HANDLE pvVar2;
  
  pvVar1 = FUN_0043e07c(param_1);
  pvVar2 = (HANDLE)0x0;
  if (pvVar1 != (HANDLE)0x0) {
    pvVar2 = (HANDLE)FUN_00442f94((int)pvVar1,param_1,0,'\0');
    if (pvVar2 == (HANDLE)0x0) {
      pvVar2 = pvVar1;
    }
  }
  return pvVar2;
}

