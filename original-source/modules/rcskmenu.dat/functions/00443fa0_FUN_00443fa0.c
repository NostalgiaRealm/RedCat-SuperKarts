/*
 * FUN_00443fa0 at 00443fa0
 * undefined1 __register FUN_00443fa0(int param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00443fa0-00443ff7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_00443fa0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char local_10;
  undefined3 uStack_f;
  
  _local_10 = CONCAT31((int3)((uint)param_3 >> 8),1);
  if (*(short *)(param_1 + 0x1e2) != 0) {
    (**(code **)(param_1 + 0x1e0))
              (*(undefined4 *)(param_1 + 0x1e4),param_1,param_3,&local_10,param_2);
  }
  if ((local_10 != '\0') && (iVar1 = FUN_004405f0(param_1,0xb039,param_2,param_3), iVar1 == 0)) {
    return 1;
  }
  return 0;
}

