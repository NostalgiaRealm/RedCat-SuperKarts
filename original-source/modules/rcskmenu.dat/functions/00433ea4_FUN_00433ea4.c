/*
 * FUN_00433ea4 at 00433ea4
 * undefined __register FUN_00433ea4(int * param_1, undefined4 param_2, undefined4 param_3, undefined1 param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 00433ea4-00433eef
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00433ea4(int *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  
  bVar1 = FUN_00433874((int)param_1);
  if (bVar1) {
    (**(code **)(*param_1 + 0x30))
              (param_1,param_5,param_2,
               CONCAT31((int3)((*(uint *)(&DAT_0047b7f4 + (uint)*(byte *)(param_1 + 0xd) * 4) |
                               *(uint *)(&DAT_0047b804 + (uint)*(byte *)((int)param_1 + 0x37) * 4))
                              >> 8),param_4),
               *(uint *)(&DAT_0047b7f4 + (uint)*(byte *)(param_1 + 0xd) * 4) |
               *(uint *)(&DAT_0047b804 + (uint)*(byte *)((int)param_1 + 0x37) * 4),param_6,param_3);
  }
  return;
}

