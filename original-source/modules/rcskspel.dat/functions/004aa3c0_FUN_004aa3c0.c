/*
 * FUN_004aa3c0 at 004aa3c0
 * undefined FUN_004aa3c0(void)
 * Address ranges: 004aa3c0-004aa42f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004aa3c0(int param_1,int param_2,undefined2 param_3)

{
  if (*(int *)(param_1 + 4) == 0) {
    FUN_004afee0(s__s__d____mesh_has_not_been_initi_004fd30c,s___mesh_inl_004fd168,0x3c);
  }
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x9c))) {
    *(undefined2 *)(*(int *)(param_1 + 0x98) + param_2 * 2) = param_3;
    return;
  }
  FUN_004afee0(s__s__d____getting_index____d___is_004fd18c,s___mesh_inl_004fd168,0x40,param_2,
               *(undefined4 *)(param_1 + 0x7c));
  *(undefined2 *)(*(int *)(param_1 + 0x98) + param_2 * 2) = param_3;
  return;
}

