function TextWriter({ text, interval }) {
        const [currentText, setCurrentText] = useState("");
        const [index, setIndex] = useState(0);
    
        useEffect(() => {
            const timer = setInterval(() => {
                if (index >= text.length) {
                    clearInterval(timer);
                } else {
                    setCurrentText((prevText) => prevText + text[index]);
                    setIndex((prevIndex) => prevIndex + 1);
                }
            }, interval);
    
            return () => clearInterval(timer);
        }, [index, interval, text]);
    
        return <div>{currentText}</div>;
    }

    <TextWriter text="Hello, world!" interval={100} />
