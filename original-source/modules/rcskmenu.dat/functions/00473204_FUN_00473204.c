/*
 * FUN_00473204 at 00473204
 * undefined __register FUN_00473204(void)
 * Address ranges: 00473204-00473241
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473204(void)

{
  int iVar1;
  
  iVar1 = FUN_00402b74(2);
  FUN_0045c5cc(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),
               (&DAT_0047c4f4)
               [iVar1 + (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x24) * 2]);
  return;
}

