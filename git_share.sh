echo "enter the assigment number"
read n

echo "Edit Message (leave Blank for default)"
read msg

message="Matgeo-$n"

if [ -n "$msg" ]; then
message=$msg
fi

cp -rf "matgeo-$n" "../Share_Personal_Repo/Share"

cd "../Share_Personal_Repo/Share"
git add .
git commit -m "$message"
git push origin main


