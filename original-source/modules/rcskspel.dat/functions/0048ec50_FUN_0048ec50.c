/*
 * FUN_0048ec50 at 0048ec50
 * undefined FUN_0048ec50(void)
 * Address ranges: 0048ec50-0048eccf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0048ec50(int param_1)

{
  LPVOID *ppv;
  HRESULT HVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_4;
  
  ppv = (LPVOID *)(param_1 + 4);
  local_4 = param_1;
  HVar1 = CoCreateInstance((IID *)&DAT_004d3460,(LPUNKNOWN)0x0,1,(IID *)&DAT_004d3470,ppv);
  if (HVar1 < 0) {
    *ppv = (LPVOID)0x0;
    return 0;
  }
  piVar3 = *ppv;
  piVar4 = &local_4;
  iVar2 = (**(code **)*piVar3)(piVar3,&DAT_004d3450);
  if (iVar2 < 0) {
    FUN_0048ecd0();
    return 0;
  }
  iVar2 = (**(code **)(*piVar4 + 0x1c))(piVar4,param_1 + 8);
  (**(code **)(*piVar3 + 8))(piVar3);
  if (iVar2 < 0) {
    FUN_0048ecd0();
    return 0;
  }
  return 1;
}

