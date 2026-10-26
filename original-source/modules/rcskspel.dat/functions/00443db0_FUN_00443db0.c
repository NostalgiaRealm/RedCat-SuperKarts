/*
 * FUN_00443db0 at 00443db0
 * undefined FUN_00443db0(void)
 * Address ranges: 00443db0-00443e7b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00443db0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_c [12];
  
  iVar2 = DAT_00508638 * 0x178;
  FUN_00498b20();
  FUN_00498bd0();
  *(undefined4 *)(iVar2 + 0x80 + DAT_00680ba0) = 0;
  FUN_0041d6c0(6);
  puVar1 = (undefined4 *)
           FUN_00445120(local_c,param_1,*(undefined4 *)(param_2 + 4),0,
                        *(undefined4 *)(param_2 + 0xc),*(undefined1 *)(param_2 + 0x1d));
  FUN_004988a0(*puVar1,puVar1[1],puVar1[2]);
  puVar1 = (undefined4 *)FUN_00498b80(local_c);
  FUN_00498b50(*(undefined4 *)(param_2 + 0x10),*puVar1,puVar1[1],puVar1[2]);
  DAT_0053f4f4 = 0;
  return;
}

