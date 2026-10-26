/*
 * FUN_00402f10 at 00402f10
 * undefined __register FUN_00402f10(int * param_1, undefined * UNRECOVERED_JUMPTABLE, int * param_3)
 * Address ranges: 00402f10-00402f3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402f10(int *param_1,undefined *UNRECOVERED_JUMPTABLE,int *param_3)

{
  if ((undefined *)0xfeffffff < UNRECOVERED_JUMPTABLE) {
    FUN_004054a8(param_3,*(int **)(((uint)UNRECOVERED_JUMPTABLE & 0xffffff) + (int)param_1));
    return;
  }
  if ((undefined *)0xfdffffff < UNRECOVERED_JUMPTABLE) {
                    /* WARNING: Could not recover jumptable at 0x00402f27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)((int)(short)UNRECOVERED_JUMPTABLE + *param_1))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00402f29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)UNRECOVERED_JUMPTABLE)();
  return;
}

