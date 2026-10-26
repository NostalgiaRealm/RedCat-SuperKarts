/*
 * FUN_00473298 at 00473298
 * undefined __register FUN_00473298(void)
 * Address ranges: 00473298-004732d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473298(void)

{
  int iVar1;
  
  iVar1 = FUN_00402b74(2);
  FUN_0045c518(*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22),
               (&DAT_0047c4fc)
               [iVar1 + (uint)*(byte *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x24) * 2],1);
  return;
}

