/*
 * FUN_00452a04 at 00452a04
 * undefined FUN_00452a04(void)
 * Address ranges: 00452a04-00452a55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452a04(int param_1,int *param_2)

{
  FUN_0040fd94();
  (**(code **)(*param_2 + 4))
            (param_2,"Filename",*(char *)(param_1 + 8) != '\0',FUN_00452d1c,param_1,FUN_00452ccc,
             param_1);
  (**(code **)(*param_2 + 8))
            (param_2,&DAT_00452a74,*(char *)(param_1 + 8) == '\0',&LAB_00452af0,param_1,
             &LAB_00452a78,param_1);
  return;
}

