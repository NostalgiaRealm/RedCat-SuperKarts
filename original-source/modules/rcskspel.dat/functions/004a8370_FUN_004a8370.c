/*
 * FUN_004a8370 at 004a8370
 * undefined FUN_004a8370(void)
 * Address ranges: 004a8370-004a844c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004a8370(int *param_1,uint param_2)

{
  void *pvVar1;
  
  if ((int)param_2 < 1) {
    FUN_004afee0(s__s__d____trying_to_allocate_nega_004fd1f4,s_D__work_libs_DX3D_Mesh_cpp_004fd124,
                 0x134,param_1[0x1f]);
  }
  FUN_004a8490();
  if (*param_1 == 1) {
    pvVar1 = operator_new(param_2 << 5);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    param_1[0x1e] = (int)pvVar1;
    param_1[0x1f] = param_2;
    param_1[1] = 1;
  }
  else if (*param_1 == 2) {
    pvVar1 = operator_new(param_2 << 5);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    param_1[0x20] = (int)pvVar1;
    param_1[0x21] = param_2;
    param_1[1] = 2;
  }
  pvVar1 = operator_new(param_2 << 5);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  param_1[0x22] = (int)pvVar1;
  pvVar1 = operator_new(param_2);
  param_1[0x24] = (int)pvVar1;
  pvVar1 = operator_new(param_2);
  param_1[0x25] = (int)pvVar1;
  param_1[0x23] = param_2;
  return 0;
}

