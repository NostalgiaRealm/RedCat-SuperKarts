/*
 * FUN_004525d0 at 004525d0
 * undefined __register FUN_004525d0(int * param_1, HPALETTE param_2)
 * Address ranges: 004525d0-00452623
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004525d0(int *param_1,HPALETTE param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  tagPALETTEENTRY atStack_80c [256];
  uint local_40c [256];
  
  bVar4 = 0;
  GetPaletteEntries(param_2,0,0x100,atStack_80c);
  DeleteObject(param_2);
  FUN_0045043c(atStack_80c,local_40c);
  puVar2 = local_40c;
  puVar3 = (uint *)(param_1 + 0x25);
  for (iVar1 = 0x100; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + (uint)bVar4 * -2 + 1;
    puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
  }
  FUN_0045272c(param_1);
  return;
}

