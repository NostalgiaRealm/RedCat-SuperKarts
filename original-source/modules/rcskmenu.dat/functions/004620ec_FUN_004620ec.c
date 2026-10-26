/*
 * FUN_004620ec at 004620ec
 * undefined __register FUN_004620ec(int param_1, uint param_2, char param_3)
 * Address ranges: 004620ec-00462184
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004620ec(int param_1,uint param_2,char param_3)

{
  if (*(char *)(param_1 + 0x354) != '\0') {
    if (param_3 == '\x01') {
      FUN_00461b44(param_1,param_2,'\0');
      *(undefined1 *)(param_1 + 0x34e) = 0;
      (**(code **)(**(int **)(param_1 + 0x2dc) + 0x5c))(*(int **)(param_1 + 0x2dc),1);
    }
    else if (*(char *)(param_1 + 0x34e) == '\0') {
      FUN_0045c720(0x32);
      DAT_0047e1dc = *(undefined1 *)(param_1 + 0x34c);
      *(char *)(param_1 + 0x34c) = (char)param_2;
      FUN_00458ea4(*(int *)(*(int *)PTR_DAT_0047c670 + 0x88),param_2,0);
      FUN_00461b44(param_1,param_2,'\x01');
      *(undefined1 *)(param_1 + 0x34e) = 1;
      (**(code **)(**(int **)(param_1 + 0x2dc) + 0x5c))(*(int **)(param_1 + 0x2dc),0);
    }
    FUN_00461d74(param_1);
  }
  return;
}

