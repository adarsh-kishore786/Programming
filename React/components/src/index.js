import React from "react";
import ReactDOM from "react-dom";
import CommentDetail from "./CommentDetail";
import faker from "faker";

const App = () => {
    return (
        <div className="ui container comments">
            <CommentDetail
                author="Sam"
                timeAgo="Today at 4:45PM"
                comText="Nice blog!"
                profileImg={faker.image.avatar()}
            />
            <CommentDetail
                author="Alex"
                timeAgo="Today at 2:00AM"
                comText="Motivating!"
                profileImg={faker.image.avatar()}
            />
            <CommentDetail
                author="Jane"
                timeAgo="Yesterday at 6:00PM"
                comText="We need more people like you"
                profileImg={faker.image.avatar()}
            />
        </div>
    );
};

ReactDOM.render(
    <App />,
    document.querySelector("#root")
);
