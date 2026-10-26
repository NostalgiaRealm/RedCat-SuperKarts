/*
 * FUN_0048edc0 at 0048edc0
 * undefined FUN_0048edc0(void)
 * Address ranges: 0048edc0-0048ee0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048edc0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_4;
  
  local_4 = param_1;
  cVar1 = FUN_0048eba0();
  if (cVar1 != '\0') {
    piVar3 = *(int **)(param_1 + 4);
    piVar4 = (int *)&DAT_004d3480;
    iVar2 = (**(code **)*piVar3)(piVar3,&DAT_004d3480,&local_4);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*piVar4 + 0x1c))(piVar4);
      (**(code **)(*piVar3 + 8))(piVar3);
      if (-1 < iVar2) {
        FUN_0048ec10(3);
      }
    }
  }
  return;
}

