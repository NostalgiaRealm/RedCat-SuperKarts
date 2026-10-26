/*
 * FUN_00444cb4 at 00444cb4
 * undefined __register FUN_00444cb4(int * param_1)
 * Address ranges: 00444cb4-00444cfb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444cb4(int *param_1)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x4c))();
  if ((cVar1 == '\0') && (param_1[9] != 0)) {
    FUN_0044244c(param_1,'\0');
  }
  bVar2 = FUN_00445a20((int)param_1);
  if ((bVar2) && ((*(byte *)(param_1 + 8) & 0x10) == 0)) {
    cVar1 = (**(code **)(*param_1 + 0x4c))();
    EnableWindow((HWND)param_1[0x53],-(uint)(cVar1 != '\0'));
  }
  return;
}

