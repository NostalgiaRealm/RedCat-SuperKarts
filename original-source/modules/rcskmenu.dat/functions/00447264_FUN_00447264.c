/*
 * FUN_00447264 at 00447264
 * undefined __register FUN_00447264(int param_1)
 * Address ranges: 00447264-004472aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447264(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (param_1 != *(int *)(*(int *)(param_1 + 0x1c) + 100)) {
    iVar2 = *(int *)(param_1 + 0x14);
  }
  if (*(char *)(iVar2 + 0x10) != '\x01') {
    if (*(char *)(iVar2 + 0x10) == '\x02') {
      FUN_00447318(param_1,'\x02');
    }
    else {
      piVar1 = FUN_0040ac64((int *)&DAT_004070f4,'\x01',(undefined4 *)0x0);
      FUN_00403604(piVar1);
    }
    return;
  }
  FUN_00447318(param_1,'\x01');
  return;
}

