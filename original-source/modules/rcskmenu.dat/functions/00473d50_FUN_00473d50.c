/*
 * FUN_00473d50 at 00473d50
 * undefined __register FUN_00473d50(int param_1)
 * Address ranges: 00473d50-00473db2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473d50(int param_1)

{
  *(undefined1 *)(param_1 + 0x338) =
       *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x22);
  (**(code **)(**(int **)(param_1 + 0x328) + 0xb8))
            (*(int **)(param_1 + 0x328),*(char *)(param_1 + 0x339) == '\0');
  (**(code **)(**(int **)(param_1 + 0x2f0) + 0xb8))
            (*(int **)(param_1 + 0x2f0),*(char *)(param_1 + 0x339) == '\x01');
  (**(code **)(**(int **)(param_1 + 0x2f4) + 0xb8))
            (*(int **)(param_1 + 0x2f4),*(char *)(param_1 + 0x339) == '\x02');
  return;
}

