/*
 * FUN_00408937 at 00408937
 * longlong __fastcall FUN_00408937(undefined4 param_1, uint param_2)
 * Address ranges: 00408937-00408983
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00408937(undefined4 param_1,uint param_2)

{
  LPVOID lpTlsValue;
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined8 uVar3;
  
  if (DAT_0040ef40 == 0xffffffff) {
LAB_00408943:
    return (ulonglong)param_2 << 0x20;
  }
  uVar3 = FUN_004088ac(param_1,param_2);
  lpTlsValue = (LPVOID)uVar3;
  uVar2 = 0;
  if (lpTlsValue != (LPVOID)0x0) {
    iVar1 = FUN_004090a6(extraout_ECX,(int)lpTlsValue);
    if (iVar1 == 0) {
      FUN_0040650f();
      goto LAB_00408943;
    }
    TlsSetValue(DAT_0040ef40,lpTlsValue);
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}

