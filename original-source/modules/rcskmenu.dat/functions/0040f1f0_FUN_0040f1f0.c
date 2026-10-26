/*
 * FUN_0040f1f0 at 0040f1f0
 * undefined __register FUN_0040f1f0(undefined * param_1, HMODULE param_2, undefined4 * param_3)
 * Address ranges: 0040f1f0-0040f263;0040f26d-0040f272
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040f1f0(undefined *param_1,HMODULE param_2,undefined4 *param_3)

{
  LPCSTR lpName;
  HRSRC pHVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar4;
  LPCSTR lpType;
  
  if (param_2 == (HMODULE)0x0) {
    param_2 = DAT_0047d4dc;
  }
  lpType = (LPCSTR)0xa;
  lpName = FUN_00403f94(param_1);
  pHVar1 = FindResourceA(param_2,lpName,lpType);
  if (pHVar1 != (HRSRC)0x0) {
    piVar2 = FUN_00411d68((int *)&PTR_FUN_0040e604,'\x01',param_2,(LPCSTR)0xa,param_1);
    uVar4 = *in_FS_OFFSET;
    *in_FS_OFFSET = &stack0xffffffe0;
    uVar3 = FUN_00411a0c((int)piVar2,(int *)*param_3);
    *param_3 = uVar3;
    *in_FS_OFFSET = uVar4;
    FUN_00402eac(piVar2);
    return;
  }
  return;
}

