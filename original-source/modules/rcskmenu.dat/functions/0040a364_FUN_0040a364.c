/*
 * FUN_0040a364 at 0040a364
 * undefined __register FUN_0040a364(int param_1)
 * Address ranges: 0040a364-0040a3b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a364(int param_1)

{
  char cVar1;
  int iVar2;
  double local_18;
  int local_10;
  int local_c;
  undefined1 local_8;
  
  local_10 = 1;
  cVar1 = FUN_0040a120(param_1,&local_10,&local_18);
  if ((cVar1 != '\0') && (iVar2 = FUN_00403dd0(param_1), iVar2 < local_10)) {
    return;
  }
  local_8 = 0xb;
  local_c = param_1;
  FUN_00407bc4((undefined4 *)PTR_PTR_0047c6d8,&local_c,0);
  return;
}

