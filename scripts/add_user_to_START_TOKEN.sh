for i in `ls`; do
  pushd $i
  sed -i '' s,START_TOKEN___\ \\.,START_TOKEN___\ $i,g DIRSUMMARY.txt
  popd
done
